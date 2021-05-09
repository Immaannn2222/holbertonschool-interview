#!/usr/bin/python3
"""INTERVIEW"""
import requests


def count_words(subreddit, word_list, count_dict={}, after=""):
    """recursive function that queries the Reddit API"""
    if len(count_dict) <= 0:
        for word in word_list:
            count_dict[word.lower()] = 0

    if after is None:
        sorted_count_dict = dict(sorted(
            count_dict.items(),
            key=lambda x: (-x[1], x[0])
            ))
        for k, v in sorted_count_dict.items():
            if v > 0:
                print("{}: {}".format(k, v))
        return None
    h = {'user-agent': 'xxxx'}
    url = 'https://api.reddit.com/r/{}/hot.json'.format(
        subreddit)
    resp = requests.get(url, headers=h, params={
        'limit': 100,
        'after': after
    })
    if resp.status_code != 200:
        return None
    else:
        try:
            r = resp.json()
        except Exception:
            return
        after = resp.json().get("data").get("after")

        for post in r['data']['children']:
            x = post['data']['title']
            words = (x.lower()).split()
        for item in word_list:
            count_dict[item.lower()] += words.count(
                        item.lower())
    count_words(subreddit, word_list, count_dict, after)
