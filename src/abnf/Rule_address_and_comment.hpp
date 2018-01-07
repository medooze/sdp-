/* -----------------------------------------------------------------------------
 * Rule_address_and_comment.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Jan 07 16:41:36 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_address_and_comment_hpp
#define Rule_address_and_comment_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_address_and_comment : public Rule
{
public:
  Rule_address_and_comment(const std::string& spelling, const std::vector<const Rule*>& rules);
  Rule_address_and_comment(const Rule_address_and_comment& rule);

  Rule_address_and_comment& operator=(const Rule_address_and_comment& rule);

  const Rule_address_and_comment* clone(void) const;

  static const Rule_address_and_comment* parse(ParserContext& context);

  void* accept(Visitor& visitor) const;
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
