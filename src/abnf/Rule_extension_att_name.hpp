/* -----------------------------------------------------------------------------
 * Rule_extension_att_name.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Jan 07 16:41:36 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_extension_att_name_hpp
#define Rule_extension_att_name_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_extension_att_name : public Rule
{
public:
  Rule_extension_att_name(const std::string& spelling, const std::vector<const Rule*>& rules);
  Rule_extension_att_name(const Rule_extension_att_name& rule);

  Rule_extension_att_name& operator=(const Rule_extension_att_name& rule);

  const Rule_extension_att_name* clone(void) const;

  static const Rule_extension_att_name* parse(ParserContext& context);

  void* accept(Visitor& visitor) const;
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
