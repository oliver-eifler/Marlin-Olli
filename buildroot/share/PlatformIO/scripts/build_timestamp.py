#Olli: Show build time
#output -DMARLIN_BUILD_TIME=\"YYYY-MM-DD\ HH:MM:SS\" 
#
import time
print("-DMARLIN_BUILD_TIMESTAMP=\\\"",time.strftime("%Y-%m-%d", time.localtime()),"\ ",time.strftime("%H:%M:%S", time.localtime()),"\\\"",sep="")
