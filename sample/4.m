(*Calculate square root*)


MODULE S4Sqrt;
IMPORT Out;

VAR
    N, x:   INTEGER;

PROCEDURE IntSqrt(y: INTEGER): INTEGER;
    VAR x:  INTEGER;
BEGIN
    x:=0;
    WHILE (x+1)*(x+1) <= y DO
        x:=x+1;
    END;
    RETURN x;
END IntSqrt;

BEGIN
    N:=25;
    x:=IntSqrt(N);
    Out.Int(x,0); Out.Ln;
END S4Sqrt.