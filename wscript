import os

srcdir = './src/'
bldir = 'build'
VERSION = '0.1.0'

def set_options(opt):
	opt.tool_options('compiler_cxx')

def configure(conf):
	conf.check_tool('compiler_cxx')
	conf.check_tool('node_addon')

	conf.env.CXXFLAGS = ['-DLINUX', '-ldl', '-lstdc++']

def build(bld):
	obj = bld.new_task_gen('cxx', 'shlib', 'node_addon')
	obj.target = 'gpu'
	obj.source = """
		src/gpu.cc
		src/gpu-helpers.cc
		src/gpu-bindings.cc
	"""

def shutdown():
	if os.path.exists("build/default/gpu.node"):
		os.system("cp build/default/gpu.node ./bin");
