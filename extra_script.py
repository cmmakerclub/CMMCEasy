from SCons.Script import DefaultEnvironment

env = DefaultEnvironment()
env['BOARD_OPTIONS']['upload']['resetmethod'] = 'ck'
