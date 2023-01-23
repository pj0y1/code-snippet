import System.Random
import Data.List

randoms' :: (RandomGen g, Random a) => g -> [a]
randoms' g = 
	let (item,newgen) = random g
	in item : randoms' newgen

randomGF :: (RandomGen g, Random a ) => Int -> g -> ([a], g)
randomGF 0 gen = ([], gen)
randomGF n gen = 
	let (item,newgen) = random gen ;
		(restList, finalGen) = randomGF (n-1) newgen
	in (item:restList, finalGen)

main = do
	gen <- getStdGen
	let ran = take 40 $ randomRs ('a','z') gen
	print $ splitAt 20 ran
