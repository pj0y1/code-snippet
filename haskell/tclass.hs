data Trafficlight  = Red | Green | Yellow

instance Eq Trafficlight where
	Red == Red = True
	Green == Green = True
	Yellow == Yellow = True
	_ == _ = False

instance Show Trafficlight where
	show Red = "Red Light"
	show Green = "Green Light"
	show Yellow = "Yellow Light"
-- if want to overwrite show function for Trafficlight, should declare instance of Show, or else simply deriving would do

class Yesno a where
	yesno :: a -> Bool

instance Yesno [a] where
	yesno [] = False
	yesno _ = True

instance Yesno Int where
	yesno 0 = False
	yesno _ = True

instance Yesno Bool where
	yesno = id

instance Yesno (Maybe a) where
	yesno Nothing = False
	yesno _ = True

yesnoIf :: Yesno a => a -> b -> b -> b
yesnoIf a s1 s2 = if yesno a then s1 else s2
