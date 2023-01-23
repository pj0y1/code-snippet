--import Control.Monad
import Data.Char

--main = do 
--	content <- getContents
--	putStr $ map toUpper content
-- it seems that if getContents meets EOF, it will start a new line automatically 
--	putStr (shortLinesOnly content)

shortLinesOnly :: String -> String
shortLinesOnly = unlines . filter (\l -> length l < 10) . lines 

-- after shortLinesOnly, it seems EOF is maintained, since a new line starts
main = interact shortLinesOnly

--it's like interact takes a str function as a filter, and after piping str content in, do filter the content
