/* -----------------------------------------------------------------------------
 * Rule_IPv4address.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Jan 07 16:41:36 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_IPv4address_hpp
#define Rule_IPv4address_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_IPv4address : public Rule
{
public:
  Rule_IPv4address(const std::string& spelling, const std::vector<const Rule*>& rules);
  Rule_IPv4address(const Rule_IPv4address& rule);

  Rule_IPv4address& operator=(const Rule_IPv4address& rule);

  const Rule_IPv4address* clone(void) const;

  static const Rule_IPv4address* parse(ParserContext& context);

  void* accept(Visitor& visitor) const;
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
