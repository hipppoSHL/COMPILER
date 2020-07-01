add2:
	BeginFunc
	_t0 = x + y
	n = _t0
	_t1 = n
	_t2 = n * 2
	Return _t2
	EndFunc
foo:
	BeginFunc
	a = 2
	_t3 = a
	_t4 = z * 3
	_t5 = y + _t4
	PushParam _t5
	PushParam a
	_t6 = LCall add2
	PopParam 8
	b = _t6
	_t7 = b
	Return _t7
	EndFunc
bar:
	BeginFunc
	PushParam 2
	PushParam 6
	PushParam 2020
	_t8 = LCall foo
	PopParam 12
	EndFunc
