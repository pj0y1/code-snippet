import System.IO
import Data.Char

main = do
	content <- readFile "noragami.txt"
	writeFile "noragami-cap.txt" (map toUpper content)
