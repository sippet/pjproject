/* $Id$
 */
#ifndef __PJPP_STRING_HPP__
#define __PJPP_STRING_HPP__

#include <pj/string.h>
#include <pj++/pool.hpp>
#include <pj/assert.h>

//
// String wrapper class for pj_str_t.
//
class Pj_String : public pj_str_t
{
public:
    //
    // Default constructor.
    //
    Pj_String() 
    { 
	pj_assert(sizeof(Pj_String) == sizeof(pj_str_t));
	ptr=NULL; 
        slen=0; 
    }

    //
    // Construct the buffer from a char*.
    //
    explicit Pj_String(char *str) 
    { 
	set(str);
    }

    //
    // Construct from a const char*.
    //
    Pj_String(Pj_Pool *pool, const char *src)
    {
	set(pool, src);
    }

    //
    // Construct from pj_str_t*.
    //
    explicit Pj_String(pj_str_t *s)
    {
	set(s);
    }

    //
    // Construct by copying from const pj_str_t*.
    //
    Pj_String(Pj_Pool *pool, const pj_str_t *s)
    {
	set(pool, s);
    }

    //
    // Construct from another Pj_String
    //
    explicit Pj_String(Pj_String &rhs)
    {
	set(rhs);
    }

    //
    // Construct by copying from Pj_String
    //
    Pj_String(Pj_Pool *pool, const Pj_String &rhs)
    {
	set(pool, rhs);
    }

    //
    // Construct from a char* and a length.
    //
    Pj_String(char *str, pj_size_t len)
    {
	set(str, len);
    }

    //
    // Construct from pair of pointer.
    //
    Pj_String(char *begin, char *end)
    {
	pj_strset3(this, begin, end);
    }

    //
    // Get the length of the string.
    //
    pj_size_t length() const
    {
	return pj_strlen(this);
    }

    //
    // Get the length of the string.
    //
    pj_size_t size() const
    {
	return length();
    }

    //
    // Get the string buffer.
    //
    const char *buf() const
    {
	return ptr;
    }

    //
    // Initialize buffer from char*.
    //
    void set(char *str)
    {
	pj_strset2(this, str);
    }

    //
    // Initialize by copying from a const char*.
    //
    void set(Pj_Pool *pool, const char *s)
    {
	pj_strdup2(pool->pool_(), this, s);
    }

    //
    // Initialize from pj_str_t*.
    //
    void set(pj_str_t *s)
    {
	pj_strassign(this, s);
    }

    //
    // Initialize by copying from const pj_str_t*.
    //
    void set(Pj_Pool *pool, const pj_str_t *s)
    {
	pj_strdup(pool->pool_(), this, s);
    }

    //
    // Initialize from char* and length.
    //
    void set(char *str, pj_size_t len)
    {
	pj_strset(this, str, len);
    }

    //
    // Initialize from pair of pointers.
    //
    void set(char *begin, char *end)
    {
	pj_strset3(this, begin, end);
    }

    //
    // Initialize from other Pj_String.
    //
    void set(Pj_String &rhs)
    {
	pj_strassign(this, &rhs);
    }

    //
    // Initialize by copying from a Pj_String*.
    //
    void set(Pj_Pool *pool, const Pj_String *s)
    {
	pj_strdup(pool->pool_(), this, s);
    }

    //
    // Initialize by copying from other Pj_String.
    //
    void set(Pj_Pool *pool, const Pj_String &s)
    {
	pj_strdup(pool->pool_(), this, &s);
    }

    //
    // Copy the contents of other string.
    //
    void strcpy(const pj_str_t *s)
    {
	pj_strcpy(this, s);
    }

    //
    // Copy the contents of other string.
    //
    void strcpy(const Pj_String &rhs)
    {
	pj_strcpy(this, &rhs);
    }

    //
    // Copy the contents of other string.
    //
    void strcpy(const char *s)
    {
	pj_strcpy2(this, s);
    }

    //
    // Compare string.
    //
    int strcmp(const char *s) const
    {
	return pj_strcmp2(this, s);
    }

    //
    // Compare string.
    //
    int strcmp(const pj_str_t *s) const
    {
	return pj_strcmp(this, s);
    }

    //
    // Compare string.
    //
    int strcmp(const Pj_String &rhs) const
    {
	return pj_strcmp(this, &rhs);
    }

    //
    // Compare string.
    //
    int strncmp(const char *s, pj_size_t len) const
    {
	return pj_strncmp2(this, s, len);
    }

    //
    // Compare string.
    //
    int strncmp(const pj_str_t *s, pj_size_t len) const
    {
	return pj_strncmp(this, s, len);
    }

    //
    // Compare string.
    //
    int strncmp(const Pj_String &rhs, pj_size_t len) const
    {
	return pj_strncmp(this, &rhs, len);
    }

    //
    // Compare string.
    //
    int stricmp(const char *s) const
    {
	return pj_stricmp2(this, s);
    }

    //
    // Compare string.
    //
    int stricmp(const pj_str_t *s) const
    {
	return pj_stricmp(this, s);
    }

    //
    // Compare string.
    //
    int stricmp(const Pj_String &rhs) const
    {
	return stricmp(&rhs);
    }

    //
    // Compare string.
    //
    int strnicmp(const char *s, pj_size_t len) const
    {
	return pj_strnicmp2(this, s, len);
    }

    //
    // Compare string.
    //
    int strnicmp(const pj_str_t *s, pj_size_t len) const
    {
	return pj_strnicmp(this, s, len);
    }

    //
    // Compare string.
    //
    int strnicmp(const Pj_String &rhs, pj_size_t len) const
    {
	return strnicmp(&rhs, len);
    }

    //
    // Compare contents for equality.
    //
    bool operator==(const char *s) const
    {
	return strcmp(s) == 0;
    }

    //
    // Compare contents for equality.
    //
    bool operator==(const pj_str_t *s) const
    {
	return strcmp(s) == 0;
    }

    //
    // Compare contents for equality.
    //
    bool operator==(const Pj_String &rhs) const
    {
	return pj_strcmp(this, &rhs) == 0;
    }

    //
    // Find a character in the string.
    //
    char *strchr(int chr)
    {
	return pj_strchr(this, chr);
    }

    //
    // Find a character in the string.
    //
    char *find(int chr)
    {
	return strchr(chr);
    }

    //
    // Concatenate string.
    //
    void strcat(const Pj_String &rhs)
    {
	pj_strcat(this, &rhs);
    }

    //
    // Left trim.
    //
    void ltrim()
    {
	pj_strltrim(this);
    }

    //
    // Right trim.
    //
    void rtrim()
    {
	pj_strrtrim(this);
    }

    //
    // Left and right trim.
    //
    void trim()
    {
	pj_strtrim(this);
    }

    //
    // Convert to unsigned long.
    //
    unsigned long to_ulong() const
    {
	return pj_strtoul(this);
    }

    //
    // Convert from unsigned long.
    //
    void from_ulong(unsigned long value)
    {
        slen = pj_utoa(value, ptr);
    }

    //
    // Convert from unsigned long with padding.
    //
    void from_ulong_with_pad(unsigned long value, int min_dig=0, int pad=' ')
    {
        slen = pj_utoa_pad(value, ptr, min_dig, pad);
    }


private:
    //Pj_String(const Pj_String &rhs) {}
    void operator=(const Pj_String &rhs) { pj_assert(false); }
};

#endif	/* __PJPP_STRING_HPP__ */

