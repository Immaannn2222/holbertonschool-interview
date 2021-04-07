#!/usr/bin/node

const request = require('request');
const address = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
request(address, async (error, response, body) => {
  if (!error) {
    const characters = JSON.parse(body).characters;
    for (const i in characters) {
      await new Promise((resolve, reject) => {
        request(characters[i], (error, response, body) => {
          if (!error) {
            console.log(JSON.parse(body).name);
            resolve();
          }
        });
      });
    }
  }
});
