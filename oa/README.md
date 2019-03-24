一个巨傻逼的错误：
  26个字母给的valueSet是String，在判断是否相等的时候应该是``` valueSet[str[i]-'a'] == '0' ``` But not ```valueSet[str[i]-'a'] == 0```我一直在提交前最后一分钟才发现的，想了很久为什么一个test case都没过...不过还是有一半没过也没来得及查是为什么

[Two operations get to the target, return minimun edit:  ](https://www.geeksforgeeks.org/convert-number-m-n-using-minimum-number-given-operations/) 这个也好傻逼啊！7/11 test case passed，剩下的是terminate due to timeout。没自己想是corner case还是我的算法太慢了，应该不至于吧_(:з」∠)_
