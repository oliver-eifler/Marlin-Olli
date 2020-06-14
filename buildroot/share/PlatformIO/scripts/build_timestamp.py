import time

print("-D MARLIN_BUILD_TIMESTAMP=\"%s\"" % time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))