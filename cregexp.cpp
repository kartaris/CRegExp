#include "include/cregexp.h"

namespace
{
bool matchImpl(const char *pattern, const char *subject);
bool matchStar(const char *pattern, const char *subject);

bool matchStar(const char *pattern, const char *subject)
{
    for(;;)
    {
        if(matchImpl(pattern, subject))
            return true;
        if(*subject == '\0')
            return false;
        *subject++;
    }
}

/**
 * Implementation for regex match algorithm
 * @param pattern
 * @param subject
 * @return
 */
bool matchImpl(const char *pattern, const char *subject)
{
    // End of pattern
    if(pattern[0] == '\0')
        return true;

    // Zero or more any symbol
    if(pattern[0] == '*')
        return matchStar(pattern + 1, subject);

    // One any symbol
    if(pattern[0] == '?')
    {
        if(subject[0] == '\0')
            return false;
        if(pattern[1] == '\0' && subject[1] != '\0')
            return false;

        return matchImpl(pattern + 1, subject + 1);
    }

    if(*subject != '\0' && pattern[0] == *subject)
    {
        if(pattern[1] == '\0')
        {
            // Pattern doesn't end with ? or * token and there is more symbols in subject
            return subject[1] == '\0';
        }
        return matchImpl(pattern + 1, subject + 1);
    }
    return false;
}
} // namespace

bool cregexp::match(const char *pattern, const char *subject)
{
    // Checking if no pattern given for quit without making any other checks
    if(!pattern || pattern[0] == '\0')
        return true;

    if(pattern[0] != '*' && pattern[0] != '?' && pattern[0] != subject[0])
        return false;

    return matchImpl(pattern, subject);
}