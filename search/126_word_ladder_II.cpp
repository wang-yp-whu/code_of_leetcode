#include "m.h"

class Solution {
public:
    // 主函数：寻找从 beginWord 到 endWord 的所有最短转换路径
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ladder;
        unordered_set<string> wordDict(wordList.begin(), wordList.end()); // 用哈希集合存储字典，方便查找

        // 如果 endWord 不在字典中，直接返回空结果
        if (!wordDict.count(endWord)) {
            return ladder;
        }

        // 移除 beginWord 和 endWord，避免重复处理
        wordDict.erase(beginWord);
        wordDict.erase(endWord);

        // 双向 BFS 的初始化
        unordered_set<string> smallQueue{beginWord}, largeQueue{endWord};
        unordered_map<string, vector<string>> nextWords; // 记录每个单词的下一层单词
        bool reversed = false, found = false; // reversed 用于标记是否反转路径，found 用于标记是否找到路径

        while (!smallQueue.empty()) {
            unordered_set<string> nextQueue;

            for (const auto& word : smallQueue) {
                string currentWord = word;
                for (int i = 0; i < currentWord.size(); ++i) {
                    char originalChar = currentWord[i];
                    for (int j = 0; j < 26; ++j) {
                        currentWord[i] = 'a' + j;
                        if (largeQueue.count(currentWord)) {
                            // 如果找到路径，根据 reversed 决定路径方向
                            if (reversed) {
                                nextWords[currentWord].push_back(word);
                            } else {
                                nextWords[word].push_back(currentWord);
                            }
                            found = true;
                        }
                        if (wordDict.count(currentWord)) {
                            // 如果当前单词在字典中，加入下一层队列
                            if (reversed) {
                                nextWords[currentWord].push_back(word);
                            } else {
                                nextWords[word].push_back(currentWord);
                            }
                            nextQueue.insert(currentWord);
                        }
                    }
                    currentWord[i] = originalChar; // 恢复原始字符
                }
            }

            if (found) {
                break; // 如果找到路径，退出循环
            }

            // 移除已经处理过的单词，避免重复处理
            for (const auto& word : nextQueue) {
                wordDict.erase(word);
            }

            // 更新队列，保持 smallQueue 始终是较小的队列
            if (nextQueue.size() <= largeQueue.size()) {
                smallQueue = nextQueue;
            } else {
                reversed = !reversed; // 反转路径方向
                smallQueue = largeQueue;
                largeQueue = nextQueue;
            }
        }

        // 如果找到路径，使用回溯法构建所有路径
        if (found) {
            vector<string> path{beginWord};
            backtracking(beginWord, endWord, nextWords, path, ladder);
        }

        return ladder;
    }

private:
    // 辅函数：回溯法构建路径
    void backtracking(const string& currentWord, const string& endWord,
                      unordered_map<string, vector<string>>& nextWords,
                      vector<string>& path, vector<vector<string>>& ladder) {
        if (currentWord == endWord) {
            ladder.push_back(path); // 如果当前单词是目标单词，将路径加入结果
            return;
        }

        if (!nextWords.count(currentWord)) {
            return; // 如果当前单词没有下一层单词，返回
        }

        for (const auto& nextWord : nextWords[currentWord]) {
            path.push_back(nextWord); // 修改当前节点状态
            backtracking(nextWord, endWord, nextWords, path, ladder); // 递归处理下一层单词
            path.pop_back(); // 恢复当前节点状态
        }
    }
};