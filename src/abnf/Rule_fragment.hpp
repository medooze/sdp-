/* -----------------------------------------------------------------------------
 * Rule_fragment.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Jan 07 16:41:36 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_fragment_hpp
#define Rule_fragment_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_fragment : public Rule
{
public:
  Rule_fragment(const std::string& spelling, const std::vector<const Rule*>& rules);
  Rule_fragment(const Rule_fragment& rule);

  Rule_fragment& operator=(const Rule_fragment& rule);

  const Rule_fragment* clone(void) const;

  static const Rule_fragment* parse(ParserContext& context);

  void* accept(Visitor& visitor) const;
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
