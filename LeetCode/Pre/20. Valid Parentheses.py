class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        dic = {"}":"{", ")":"(", "]":"["}
        for c in s:
            if c in dic.values():
                st.append(c)
            elif c in dic.keys():
                if st == [] or dic[c] != st.pop():
                    return False
        return st == []
