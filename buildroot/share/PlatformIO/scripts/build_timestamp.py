#Olli: Show build time
#output -DMARLIN_BUILD_TIMESTAMP=STR_SP_STR("YYYY-MM-DD","HH:MM:SS") 
#
import time
quote = "\\\""
timestamp = time.localtime()
print("-DMARLIN_BUILD_TIMESTAMP=STR_SP_STR(",quote,time.strftime("%Y-%m-%d", timestamp),quote,",",quote,time.strftime("%H:%M:%S", timestamp),quote,")",sep="")
