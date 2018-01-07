/* -----------------------------------------------------------------------------
 * Rule_alpha_numeric.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Jan 07 16:41:36 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_alpha_numeric_hpp
#define Rule_alpha_numeric_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_alpha_numeric : public Rule
{
public:
  Rule_alpha_numeric(const std::string& spelling, const std::vector<const Rule*>& rules);
  Rule_alpha_numeric(const Rule_alpha_numeric& rule);

  Rule_alpha_numeric& operator=(const Rule_alpha_numeric& rule);

  const Rule_alpha_numeric* clone(void) const;

  static const Rule_alpha_numeric* parse(ParserContext& context);

  void* accept(Visitor& visitor) const;
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
