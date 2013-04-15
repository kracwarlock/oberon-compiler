main:
li	$t0,3
sw	$t0,12($sp)
li	$t0,8
sw	$t0,16($sp)
li	$t0,0
sw	$t0,20($sp)
lw	$t7,12($sp)
lw	$t8,16($sp)
ble	$t7,$t8,M0
li	$t9,0
b	End0

M0:
li	$t9,1

End0:
beqz	$t9,L0
lw	$t7,16($sp)
lw	$t8,20($sp)
ble	$t7,$t8,M1
li	$t9,0
b	End1

M1:
li	$t9,1

End1:
beqz	$t9,L1
li	$t0,16
sw	$t0,24($sp)
b	End2

L1:
li	$t0,100
sw	$t0,28($sp)

End2:
b	End3

L0:
li	$t0,90
sw	$t0,32($sp)

End3:
li	$v0,10
syscall
