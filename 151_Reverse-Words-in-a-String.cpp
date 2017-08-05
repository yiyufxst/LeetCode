#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWord(string &s, int start, int end) {
    	while (start < end) {
    		char temp = s[start];
    		s[start++] = s[end];
    		s[end--] = temp;
    	}
    }

    void reverseWords(string &s) {
    	int start = 0, copy = 0;
        int length = s.length();
        int leftSpaces = 0, rightSpaces = 0;

        for (int i = 0; i < length; i++) {
            if (s[i] != ' ') {
                break; 
            } else {
                leftSpaces++;
            }
        }
        if (leftSpaces == length) {
            s = "";
            return ;
        }
        for (int j = length - 1; j > 0; j--) {
            if (s[j] != ' ') {
                break;
            } else {
                rightSpaces++;
            }
        } 

        for (int i = leftSpaces; i < length - rightSpaces;) { 
            start = copy;
        	while (i < length - rightSpaces && s[i] != ' ') {
        		s[copy++] = s[i++];
        	} 
            reverseWord(s, start, copy - 1);
            if (i < length - rightSpaces && copy > 0) {
                s[copy++] = ' ';
            }   
            while (i < length - rightSpaces && s[i] == ' ') {
                i++;
        	} 
        }

        s.resize(copy);
        reverseWord(s, 0, copy - 1);
    }
};

int main() {
    Solution solution;
    string s = "  abc   efg   ";
    cout << "Result:" << s << "(start)"<<endl;  
    solution.reverseWords(s);
    cout << "Result:" << s << "(end)"<<endl;  
}
