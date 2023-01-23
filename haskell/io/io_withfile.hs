import System.IO

withFile' :: FilePath -> IOMode -> (Handle -> IO r) -> IO r
withFile' path mode f = do
	handle <- openFile path mode
	result <- f handle
	hClose handle
	return result

--can't omit result <- f handle and return result, because type mismatching

main = do
	withFile' "noragami.txt" ReadMode (\h -> do
		hSetBuffering h $ BlockBuffering (Just 2048)
		content <- hGetContents h
		putStr content)
