/**
 * Implement a simplified version of Twitter which allows users to post tweets, follow/unfollow each other,
 * and view the 10 most recent tweets within their own news feed.

Users and tweets are uniquely identified by their IDs (integers).

Implement the following methods:

Twitter() Initializes the twitter object.
void postTweet(int userId, int tweetId) Publish a new tweet with ID tweetId by the user userId. You may
assume that each tweetId is unique.
List<Integer> getNewsFeed(int userId) Fetches at most the 10 most recent tweet IDs in the user's news feed.
 Each item must be posted by users who the user is following or by the user themself. Tweets IDs should be
  ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId follows the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId unfollows the user with ID followeeId.
Example 1:

Input:
["Twitter", "postTweet", [1, 10], "postTweet", [2, 20], "getNewsFeed", [1], "getNewsFeed", [2], "follow", [1, 2], "getNewsFeed", [1], "getNewsFeed", [2], "unfollow", [1, 2], "getNewsFeed", [1]]

Output:
[null, null, null, [10], [20], null, [20, 10], [20], null, [10]]

Explanation:
Twitter twitter = new Twitter();
twitter.postTweet(1, 10); // User 1 posts a new tweet with id = 10.
twitter.postTweet(2, 20); // User 2 posts a new tweet with id = 20.
twitter.getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
twitter.getNewsFeed(2);   // User 2's news feed should only contain their own tweets -> [20].
twitter.follow(1, 2);     // User 1 follows user 2.
twitter.getNewsFeed(1);   // User 1's news feed should contain both tweets from user 1 and user 2 -> [20, 10].
twitter.getNewsFeed(2);   // User 2's news feed should still only contain their own tweets -> [20].
twitter.unfollow(1, 2);   // User 1 unfollows user 2.
twitter.getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
Constraints:

1 <= userId, followerId, followeeId <= 100
0 <= tweetId <= 1000
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

class Twitter
{
private:
    int timestamp;
    map<int, vector<pair<int, int>>> mUserProfile; // userId -> vector of (timestamp, tweetId)
    map<int, vector<int>> mTrackFollowers; // userId -> vector of followeeIds
public:
    Twitter() : timestamp(0)
    {
        // Maps are default initialized as empty
    }

    /// @brief adding an entry in mUserProfile
    /// @param userId 
    /// @param tweetId 
    void postTweet(int userId, int tweetId)
    {
        // Store tweet with timestamp for proper chronological ordering
        mUserProfile[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<pair<int, int>> allTweets; // (timestamp, tweetId)
        
        // Add user's own tweets
        if(mUserProfile.find(userId) != mUserProfile.end())
        {
            for(const auto& tweet : mUserProfile[userId])
            {
                allTweets.push_back(tweet);
            }
        }
        
        // Add tweets from followed users
        if(mTrackFollowers.find(userId) != mTrackFollowers.end())
        {
            for(int followeeId : mTrackFollowers[userId])
            {
                if(mUserProfile.find(followeeId) != mUserProfile.end())
                {
                    for(const auto& tweet : mUserProfile[followeeId])
                    {
                        allTweets.push_back(tweet);
                    }
                }
            }
        }
        
        // Sort by timestamp in descending order (most recent first)
        sort(allTweets.begin(), allTweets.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        // Extract tweet IDs and return at most 10 most recent tweets
        vector<int> newsFeed;
        int count = min(10, (int)allTweets.size());
        for(int i = 0; i < count; i++)
        {
            newsFeed.push_back(allTweets[i].second);
        }
        
        return newsFeed;
    }

    void follow(int followerId, int followeeId)
    {
        // Only add to followers list, not to user profile (user profile is for tweets only)
        // Check if not already following to avoid duplicates
        auto& followers = mTrackFollowers[followerId];
        if(followerId == followeeId)
            return;
        if(find(followers.begin(), followers.end(), followeeId) == followers.end())
        {
            mTrackFollowers[followerId].push_back(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId)
    {
        // Erase the followeeId from mTrackFollowers for the given followerId
        if(mTrackFollowers.find(followerId) != mTrackFollowers.end())
        {
            auto& followers = mTrackFollowers[followerId];
            followers.erase(remove(followers.begin(), followers.end(), followeeId), followers.end());
        }
    }
};

int main(int argc, char const *argv[])
{
    unique_ptr<Twitter> twitter = make_unique<Twitter>();
    twitter->postTweet(1, 10); // User 1 posts a new tweet with id = 10.
    twitter->postTweet(2, 20); // User 2 posts a new tweet with id = 20.
    twitter->getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
    twitter->getNewsFeed(2);   // User 2's news feed should only contain their own tweets -> [20].
    twitter->follow(1, 2);     // User 1 follows user 2.
    twitter->getNewsFeed(1);   // User 1's news feed should contain both tweets from user 1 and user 2 -> [20, 10].
    twitter->getNewsFeed(2);   // User 2's news feed should still only contain their own tweets -> [20].
    twitter->unfollow(1, 2);   // User 1 unfollows user 2.
    twitter->getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
    return 0;
}
