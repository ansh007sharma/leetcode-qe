Problem-Solution:-
  
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
  
Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 
Constraints:
1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
  
======================================================================================================================================================================
  
Solution:-
  
class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        map<char, string>chToWordMap;
        map<string, char>wordToChMap;
        s.push_back(' ');
        string currWord = "";
        int chIdx = 0;
        for (int  i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') //recording words from string
            {
                char currCh = pattern[chIdx++];
                if (chToWordMap.count(currCh))
                {
                    string alreadyMappedWord = chToWordMap[currCh];
                    if (alreadyMappedWord != currWord) return false; //one character map's to two words
                }
                else if (wordToChMap.count(currWord))
                {
                    char alreadyMappedCh = wordToChMap[currWord];
                    if (alreadyMappedCh != currCh) return false; //one word map's to two characters
                }
                else
                {
                    chToWordMap[currCh] = currWord;
                    wordToChMap[currWord] = currCh;
                }
                currWord = "";
            }
            else currWord.push_back(s[i]);
        }
        return (chIdx == pattern.size());
        
    }
};

