// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// 所有输入均为小写字母。
// 不考虑答案输出的顺序。
// 重新排序是判断是否互为错位词的方法
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;  
        int index = 0;
        // 索引是排序后的单词，值为结果vector的下标
        unordered_map<string, int> work; // 判断排序后单词是否存在，即字母组成是否一致
        for(auto str:strs)
        {
            string tmp = str;
            sort(tmp.begin(),tmp.end());
            if(work.count(tmp)) // 如果tmp及其同类变换字符串已经被加入到map中，加入到res对应的位置的尾部
            {
               res[work[tmp]].push_back(str);
            }
            else // 如果tmp及其同类变换字符串还没有被加入到map中，添加到res尾部
            {
                vector<string> vec(1,str);
                res.push_back(vec);
                work[tmp] = index++;
            }
        }
        return res;
    }
};
