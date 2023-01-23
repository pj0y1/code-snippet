--interact seems only stop receiving chars after EOF
main = interact respondToPalindrome

respondToPalindrome :: String -> String
respondToPalindrome =  unlines . map (\l -> if ((reverse l) == l) then "it's P" else "it's not P" ) . lines

