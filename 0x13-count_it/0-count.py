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
    url = "https://api.reddit.com/r/{}/hot".format(subreddit)
    params = {'limit': 100, 'after': after}
    headers = {'user-agent': 'xxxx'}
    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    if response.status_code == 200:
        after = response.json().get("data").get("after")
        posts = response.json().get("data").get("children")
        for child in posts:
            title = child.get("data").get(
                "title").lower().split(" ")
            for word in word_list:
                count_dict[word.lower()] += title.count(
                    word.lower())
    else:
        return None
    count_words(subreddit, word_list, count_dict, after)
