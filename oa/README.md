一个巨傻逼的错误：
  26个字母给的valueSet是String，在判断是否相等的时候应该是``` valueSet[str[i]-'a'] == '0' ``` But not ```valueSet[str[i]-'a'] == 0```我一直在提交前最后一分钟才发现的，想了很久为什么一个test case都没过...不过还是有一半没过也没来得及查是为什么
