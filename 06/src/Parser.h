enum cmdType { A_COMMAND, C_COMMAND, L_COMMAND };

void ParserInit(char *);
void advance();
enum cmdType commandType(char *);
char *symbol(char *);
