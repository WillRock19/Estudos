CD C:\BACKUP_SQL\TERCA\
DEL LOG.TXT
DEL VolpeApaf.bak

osql -S(local) -E -dmaster -iC:\BACKUP_SQL\TERCA\BKP_TERCA.SQL -oC:\BACKUP_SQL\TERCA\LOG.TXT

EXIT