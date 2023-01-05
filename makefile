# ----------------------------
# Makefile Options
# ----------------------------

NAME = SPQR1C
ICON = icon.png
DESCRIPTION = "SPQR - Glory to Rome! Senatus Populus!"
COMPRESSED = YES
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
$(OBJDIR)/SPQRFONTS.src: $(SRCDIR)/SPQRFONT.inc

$(SRCDIR)/SPQRFONT.inc: $(SRCDIR)/SPQRFON.fnt
	convfont -o carray -f $(SRCDIR)/SPQRFONT.fnt $(SRCDIR)/SPQRFONT.inc