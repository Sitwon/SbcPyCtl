import os,sys

def main(protos):
	line = protos.readline()
	while (line != ''):
		convert(line)
		line = protos.readline()

def convert(line):
	splitline = line.split("\t", 1)
	if len(splitline) == 1:
		splitline = line.split(" ", 1)
	return_type = splitline[0]
	arg_list = splitline[1].split('(')[1][:-3]
	arg_dict = {}
	for pair in arg_list.split(","):
		pair = pair.strip()
		if pair != "":
			pair = pair.split(" ")
			arg_dict[pair[0]] = pair[1]
	func_name = splitline[1].split()[0].split('(')[0]
	sys.stdout.write("def " + func_name + "(self")
	if func_name[:3] == "set":
		for arg in arg_dict.values():
			if arg != "pDfvObj":
				sys.stdout.write(", " + arg)
	sys.stdout.write("):\n")
	if return_type == "void":
		sys.stdout.write("\tdfvifc_c.dfv_" + func_name + "(")
		count = 0
		for arg in arg_dict.values():
			if count == 0:
				sys.stdout.write(arg)
			else:
				sys.stdout.write(", " + arg)
			count += 1
		sys.stdout.write(")\n")
	elif return_type == "char*":
		sys.stdout.write("\tcstr = create_string_buffer(1024)\n")
		sys.stdout.write("\tdfvifc_c.dfv_" + func_name + ".argtypes = [c_void_p, c_char_p, c_int]\n")
		sys.stdout.write("\tdfvifc_c.dfv_" + func_name + ".restype = c_char_p\n")
		sys.stdout.write("\treturn dfvifc_c.dfv_" + func_name + "(")
		count = 0
		for arg in arg_dict.values():
			if count == 0:
				sys.stdout.write(arg)
			else:
				sys.stdout.write(", " + arg)
			count += 1
		sys.stdout.write(", cstr, 1024")
		sys.stdout.write(")\n")
	else:
		sys.stdout.write("\treturn dfvifc_c.dfv_" + func_name + "(")
		count = 0
		for arg in arg_dict.values():
			if count == 0:
				sys.stdout.write(arg)
			else:
				sys.stdout.write(", " + arg)
			count += 1
		sys.stdout.write(")\n")
	print

if __name__=="__main__":
	protos = file(sys.argv[1], 'r')
	main(protos)

