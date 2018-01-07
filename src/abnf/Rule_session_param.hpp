/* -----------------------------------------------------------------------------
 * Rule_session_param.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Jan 07 16:41:36 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_session_param_hpp
#define Rule_session_param_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_session_param : public Rule
{
public:
  Rule_session_param(const std::string& spelling, const std::vector<const Rule*>& rules);
  Rule_session_param(const Rule_session_param& rule);

  Rule_session_param& operator=(const Rule_session_param& rule);

  const Rule_session_param* clone(void) const;

  static const Rule_session_param* parse(ParserContext& context);

  void* accept(Visitor& visitor) const;
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
