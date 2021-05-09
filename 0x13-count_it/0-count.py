#!/usr/bin/python3
"""INTERVIEW"""
import requests


def count_words(subreddit, word_list):
    """recursive function that queries the Reddit API"""
    word_list = [str.lower() for str in word_list]

    my_list = list_t(subreddit)
    my_dict = {}

    for word in word_list:
        my_dict[word] = 0
    try:
        for title in my_list:
            title_split = title.split()

            for x in title_split:
                for x_split in word_list:
                    if x.lower() == x_split.lower():
                        my_dict[x_split] += 1

        for key, val in sorted(my_dict.items(), key=lambda x: x[1],
                               reverse=True):
            if val != 0:
                print("{}: {}".format(key, val))
    except Exception:
        return None


def list_t(subreddit, my_list=[], after=None):
    """function that return all popular posts from reddit"""
    headers = {'User-agent': 'xxxx'}
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)

    parameters = {'after': after}
    res = requests.get(url, headers=headers, allow_redirects=False,
                       params=parameters)
    if res.status_code == 200:
        prox = res.json().get('data').get('after')
        if prox is not None:
            list_t(subreddit, my_list, prox)
    else:
        return None
    try:
        dic_json = res.json()
        for title_ in dic_json['data']['children']:
            my_list.append(title_['data']['title'])

        return my_list
    except Exception:
        return None
