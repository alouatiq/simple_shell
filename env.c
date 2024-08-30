#include "shell.h"

void handle_env(void)
{
    for (int i = 0; environ[i] != NULL; i++)
        printf("%s\n", environ[i]);
}

int _setenv(const char *name, const char *value, int overwrite)
{
    size_t name_len = strlen(name);
    size_t value_len = strlen(value);
    size_t len = name_len + value_len + 2;  /* +2 for '=' and null terminator */
    char *env_var = malloc(len);

    if (env_var == NULL)
        return -1;

    snprintf(env_var, len, "%s=%s", name, value);

    for (char **envp = environ; *envp != NULL; ++envp)
    {
        if (strncmp(*envp, name, name_len) == 0 && (*envp)[name_len] == '=')
        {
            if (!overwrite)
            {
                free(env_var);
                return 0;
            }
            strcpy(*envp, env_var);
            free(env_var);
            return 0;
        }
    }

    for (char **envp = environ; *envp != NULL; ++envp)
    {
        if (*(envp + 1) == NULL)
        {
            *(envp + 1) = env_var;
            *(envp + 2) = NULL;
            break;
        }
    }

    return 0;
}

int _unsetenv(const char *name)
{
    size_t name_len = strlen(name);
    char **envp = environ;

    while (*envp != NULL)
    {
        if (strncmp(*envp, name, name_len) == 0 && (*envp)[name_len] == '=')
        {
            for (char **next = envp; *next != NULL; next++)
                *next = *(next + 1);
        }
        else
        {
            envp++;
        }
    }

    return 0;
}
