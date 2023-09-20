int findpath(const char *command, char *path, size_t length)
{
        char *penv = NULL;
        unsigned int i;
        char *pcopy = strdup(penv);
        char *term = strtok(pcopy, ":");
        int pindex = 0;

        for (i = 0; environ[i] != NULL; i++)
        {
                if (strncmp(environ[i], "PATH", 5) == 0)
                {
                        penv = environ[i] + 5;
                        break;
                }
        }
        if (penv == NULL)
        {
                return (-1);
        }
        while (term != NULL)
        {
                unsigned int termlen = strlen(term);
                unsigned int comlen = strlen(command);
                unsigned int plen = termlen + 1 + comlen;

                if (plen < length)
                {
                        for (i = 0; i < termlen; i++)
                                path[pindex++] = term[i];
                        path[pindex++] = '/';
                        for (i = 0; i < comlen; i++)
                                path[pindex++] = command[i];
                }
                path[pindex] = '\0';
                if (access(path, X_OK) == 0)
                {
                        free(pcopy);
                        return (0);
                } term = strtok(NULL, ":");
        } free(pcopy);
        return (-1);
}
