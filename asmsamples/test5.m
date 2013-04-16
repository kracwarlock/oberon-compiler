MODULE LTESQ;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  k, x : y;

BEGIN
	k := 2;
	x := 16;
	CASE k OF
	  0 : x := k + k;
	& 1 : x := x + k;
	ELSE
		x := 256;
	END;

END LTESQ.