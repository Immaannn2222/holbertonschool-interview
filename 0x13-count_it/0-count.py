#!/usr/bin/python3
"""INTERVIEW"""
import requests


def count_words(subreddit, word_list, count_dict={}, after=""):
    """recursive function that queries the Reddit API"""
    if len(count_dict) <= 0:
        for item in word_list:
            count_dict[item.lower()] = 0

    if after is None:
        sorted_dict = dict(sorted(
            count_dict.items(),
            key=lambda x: (-x[1], x[0])
            ))
        for k, v in sorted_dict.items():
            if v > 0:
                print("{}: {}".format(k, v))
        return None
    h = {'user-agent': 'xxxx'}
    url = 'https://api.reddit.com/r/{}/hot.json'.format(
        subreddit)
    resp = requests.get(url, headers=h, params={
        'limit': 100,
        'after': after}, allow_redirects=False)
    if resp.status_code != 200:
        return None
    try:
        after = resp.json().get("data").get("after")
        children = resp.json().get("data").get("children")
        for post in children:
            title = post.get("data").get(
                "title").lower().split(" ")
            for item in word_list:
                count_dict[item.lower()] += title.count(
                    item.lower())
    except Exception:
        return None
    count_words(subreddit, word_list, count_dict, after)
