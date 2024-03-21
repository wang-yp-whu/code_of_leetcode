#include "m.h"

class Solution
{
public:
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int nodeNum = 0;
    vector<vector<string>> ans;

    void addWord(string& word) 
    {
        if (!wordId.count(word)) 
        {
            wordId[word] = nodeNum++;
            edge.emplace_back();
        }
    }

    void addEdge(string& word) 
    {
        addWord(word);
        int id1 = wordId[word];
        for (char& it : word) 
        {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }//如果在此处把it 改为遍历26个英文字母，那么就可以将各个单词都直接相连了
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        for (string& word : wordList) 
        {
            addEdge(word);
        }
        addEdge(beginWord);
        if (!wordId.count(endWord)) 
        {
            return ans;
        }
        int beginId = wordId[beginWord], endId = wordId[endWord];
        queue<int> que;
        que.push(beginId);
        while (!que.empty()) 
        {
            int x = que.front();
            que.pop();
            if (x == endId) 
            {
                return dis[endId] / 2 + 1;
            }
            for (int& it : edge[x]) 
            {
                if (dis[it] == INT_MAX) 
                {
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        return 0;
    }//我不会bfs求最短路时的路径，只会求最短距离
};