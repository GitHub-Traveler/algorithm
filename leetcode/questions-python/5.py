class Solution:
    def longestPalindrome(self, s: str) -> str:
        palindrome = [[False for _ in s] for _ in range(len(s))]
        size = len(s)
        for i in range(size):
            for j in range(size - i):
                if i == 0:
                    palindrome[i][j] = True
                elif i == 1:
                    palindrome[i][j] = s[j] == s[j + 1]
                else:
                    palindrome[i][j] = (s[j] == s[j + i]) and (palindrome[i - 2][j + 1])
        max_size = -1
        current_string = ""
        for i in range(size):
            for j in range(size - i):
                if palindrome[i][j] and (i + 1) > max_size:
                    current_string = s[j : j + i + 1]
                    max_size = i + 1
        return current_string
