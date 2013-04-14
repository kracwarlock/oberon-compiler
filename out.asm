main:
li	$t0,3
sw	$t0,12($sp)
li	$t0,8
sw	$t0,16($sp)
li	$t0,0
sw	$t0,20($sp)
li	$t0,1
sw	$t0,24($sp)
lw	$t0,24($sp)
beqz	$t0,L0
li	$t0,10
sw	$t0,28($sp)
b	End0

L0:
li	$t0,20
sw	$t0,32($sp)

End0:
li	$v0,10
syscall
