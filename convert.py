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
	arg_dict = []
	for pair in arg_list.split(","):
		pair = pair.strip()
		if pair != "":
			pair = pair.split(" ")
			arg_dict.append(pair[1])
	func_name = splitline[1].split()[0].split('(')[0]
	sys.stdout.write("\tdef " + func_name + "(self")
	if (func_name[:3] == "set") or (func_name[:3] == "add"):
		for arg in arg_dict:
			if arg != "pDfvObj":
				sys.stdout.write(", " + arg)
	sys.stdout.write("):\n")
	if return_type == "void":
		sys.stdout.write("\t\tdfvifc_c.dfv_" + func_name + "(")
		count = 0
		for arg in arg_dict:
			if count != 0:
				sys.stdout.write(", ")
			if arg == "pDfvObj":
				sys.stdout.write("self.")
			sys.stdout.write(arg)
			count += 1
		sys.stdout.write(")\n")
	elif return_type == "char*":
		sys.stdout.write("\t\tcstr = create_string_buffer(1024)\n")
		sys.stdout.write("\t\tdfvifc_c.dfv_" + func_name + ".argtypes = [c_void_p, c_char_p, c_int]\n")
		sys.stdout.write("\t\tdfvifc_c.dfv_" + func_name + ".restype = c_char_p\n")
		sys.stdout.write("\t\treturn dfvifc_c.dfv_" + func_name + "(")
		sys.stdout.write("self.pDfvObj, cstr, 1024")
		sys.stdout.write(")\n")
		if (len(arg_dict) != 3):
			sys.stderr.write("Warning: " + line)
			sys.stderr.write("\n")
	else:
		sys.stdout.write("\t\treturn dfvifc_c.dfv_" + func_name + "(")
		count = 0
		for arg in arg_dict:
			if count != 0:
				sys.stdout.write(", ")
			if arg == "pDfvObj":
				sys.stdout.write("self.")
			sys.stdout.write(arg)
			count += 1
		sys.stdout.write(")\n")
	print

if __name__=="__main__":
	protos = file(sys.argv[1], 'r')
	main(protos)

