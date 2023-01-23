import System.IO
main = do
{-	iamahandle <- openFile "noragami.txt" ReadMode
	print iamahandle
	content <- hGetContents iamahandle
	putStr content
	hClose iamahandle
-}
{-	withFile "noragami.txt" ReadMode (\h -> do
		content <- hGetContents h
		putStr content)
-}
	content <- withFile "noragami.txt" ReadMode hGetContents
	print content
-- we get ""
-- this way output is nothing, is it because of haskell's laziness?
-- since hGetContents :: Handle -> IO String, so this withFile function will return a IO string
-- but due to haskell laziness, after hGetContents, the file soon closed, the content gets nothing
-- content :: String, thus is nothing 

