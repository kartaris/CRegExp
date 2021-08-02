/**
 * CRegExp library implements simple regex
 * Supported tokens:
 *      '*' - matches any character zero or more times
 *      '?' - matches any character exactly one time
 */

#ifndef CREGEXPLIB_CREGEXP_H
#define CREGEXPLIB_CREGEXP_H

namespace cregexp
{
/**
 * Simple regex realization.
 * Supported tokens:
 *      '*' - matches any character zero or more times
 *      '?' - matches any character exactly one time
 * @param subject String being matched to the pattern
 * @param pattern Regex pattern
 * @return true if subject matched the pattern, false if not
 */
bool match(const char *subject, const char *pattern);
} // namespace cregexp

#endif //CREGEXPLIB_CREGEXP_H
