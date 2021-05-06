#!/usr/bin/python3
"""INTERVIEW"""
import requests


def count_words(subreddit, word_list, after=""):
    """recursive function that queries the Reddit API"""
    h = {'user-agent': 'xxxx'}
    url = 'https://api.reddit.com/r/{}/hot.json'.format(
        subreddit)
    resp = requests.get(url, headers=h, params={
        'limit': 100,
        'after': after
    })
    if resp.status_code != 200:
        return None
    try:
        r = resp.json()
    except Exception:
        return None
    titles = []
    for post in r['data']['children']:
        x = post['data']['title']
        words = (x.lower()).split()
        titles.append(words)
    answer = {}
    for item in word_list:
        answer[item] = 0
        if item in titles:
            answer[item] += item.count()
        else:
            answer[item] = 0
    for k, v in sorted(answer.items(), key=lambda x: (-x[1], x[0])):
        print("{} = {}".format(k.lower(), v))
    count_words(subreddit, word_list, after="")