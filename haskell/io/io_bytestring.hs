import qualified Data.ByteString as S
import qualified Data.ByteString.Lazy as B
import System.Environment

main = do
	(filename1:filename2:_) <- getArgs
	copyFile filename1 filename2

copyFile :: FilePath -> FilePath -> IO ()
copyFile src dest = do
	content <- B.readFile src
	B.writeFile dest content
