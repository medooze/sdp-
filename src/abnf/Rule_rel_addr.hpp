/* -----------------------------------------------------------------------------
 * Rule_rel_addr.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Jan 07 16:41:36 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_rel_addr_hpp
#define Rule_rel_addr_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_rel_addr : public Rule
{
public:
  Rule_rel_addr(const std::string& spelling, const std::vector<const Rule*>& rules);
  Rule_rel_addr(const Rule_rel_addr& rule);

  Rule_rel_addr& operator=(const Rule_rel_addr& rule);

  const Rule_rel_addr* clone(void) const;

  static const Rule_rel_addr* parse(ParserContext& context);

  void* accept(Visitor& visitor) const;
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
