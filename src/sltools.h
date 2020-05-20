#ifndef HTTPGD_SLTOOLS_H
#define HTTPGD_SLTOOLS_H

/*

inline bool is_black(int col);
inline bool is_filled(int col);

inline bool is_bold(int face);
inline bool is_italic(int face);
inline bool is_bolditalic(int face);
inline bool is_symbol(int face);

inline std::string find_alias_field(std::string& family, Rcpp::List& alias,
                                    const char* face, const char* field);

inline std::string find_user_alias(std::string& family,
                                   Rcpp::List const& aliases,
                                   int face, const char* field);

inline std::string find_system_alias(std::string& family,
                                     Rcpp::List const& aliases);

inline std::string fontname(const char* family_, int face,
                            Rcpp::List const& system_aliases,
                            Rcpp::List const& user_aliases);

inline std::string fontfile(const char* family_, int face,
                            Rcpp::List user_aliases);*/

inline bool is_black(int col) {
  return (R_RED(col) == 0) && (R_GREEN(col) == 0) && (R_BLUE(col) == 0) &&
    (R_ALPHA(col) == 255);
}

inline bool is_filled(int col) {
  return R_ALPHA(col) != 0;
}

inline bool is_bold(int face) {
  return face == 2 || face == 4;
}
inline bool is_italic(int face) {
  return face == 3 || face == 4;
}
inline bool is_bolditalic(int face) {
  return face == 4;
}
inline bool is_symbol(int face) {
  return face == 5;
}

inline std::string find_alias_field(std::string& family, Rcpp::List& alias,
                                    const char* face, const char* field) {
  if (alias.containsElementNamed(face)) {
    Rcpp::List font = alias[face];
    if (font.containsElementNamed(field))
      return font[field];
  }
  return std::string();
}

inline std::string find_user_alias(std::string& family,
                                   Rcpp::List const& aliases,
                                   int face, const char* field) {
  std::string out;
  if (aliases.containsElementNamed(family.c_str())) {
    Rcpp::List alias = aliases[family];
    if (is_bolditalic(face))
      out = find_alias_field(family, alias, "bolditalic", field);
    else if (is_bold(face))
      out = find_alias_field(family, alias, "bold", field);
    else if (is_italic(face))
      out = find_alias_field(family, alias, "italic", field);
    else if (is_symbol(face))
      out = find_alias_field(family, alias, "symbol", field);
    else
      out = find_alias_field(family, alias, "plain", field);
  }
  return out;
}

inline std::string find_system_alias(std::string& family,
                                     Rcpp::List const& aliases) {
  std::string out;
  if (aliases.containsElementNamed(family.c_str())) {
    SEXP alias = aliases[family];
    if (TYPEOF(alias) == STRSXP && Rf_length(alias) == 1)
      out = Rcpp::as<std::string>(alias);
  }
  return out;
}

inline std::string fontname(const char* family_, int face,
                            Rcpp::List const& system_aliases,
                            Rcpp::List const& user_aliases) {
  std::string family(family_);
  if (face == 5)
    family = "symbol";
  else if (family == "")
    family = "sans";
  
  std::string alias = find_system_alias(family, system_aliases);
  if (!alias.size())
    alias = find_user_alias(family, user_aliases, face, "name");
  
  if (alias.size())
    return alias;
  else
    return family;
}

inline std::string fontfile(const char* family_, int face,
                            Rcpp::List user_aliases) {
  std::string family(family_);
  if (face == 5)
    family = "symbol";
  else if (family == "")
    family = "sans";
  
  return find_user_alias(family, user_aliases, face, "file");
}

#endif /* HTTPGD_SLTOOLS_H */