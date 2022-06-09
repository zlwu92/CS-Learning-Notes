// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
// 说明：本题中，我们将空字符串定义为有效的回文串。
// 示例 1:
// 输入: "A man, a plan, a canal: Panama"
// 输出: true
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1 ;
        while(left < right)
        {
            if(!isalnum(s[left]))   left++;
            else if(!isalnum(s[right])) right--;
            else if(isdigit(s[left]) && isdigit(s[right]) && s[left] != s[right])   return false;
            // 小写97开始，大写65开始，数字48开始
            else if((s[left] + 32 - 'a') %32 != (s[right] + 32 - 'a') % 32) return false;
            else
            {
                left++; right--;
            }  
        }
        return true;
    }
};