/* -----------------------------------------------------------------------------
 * Rule_segment.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Jan 07 16:41:36 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_segment_hpp
#define Rule_segment_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_segment : public Rule
{
public:
  Rule_segment(const std::string& spelling, const std::vector<const Rule*>& rules);
  Rule_segment(const Rule_segment& rule);

  Rule_segment& operator=(const Rule_segment& rule);

  const Rule_segment* clone(void) const;

  static const Rule_segment* parse(ParserContext& context);

  void* accept(Visitor& visitor) const;
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
