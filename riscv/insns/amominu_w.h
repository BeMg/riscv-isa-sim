require_extension('A');
WRITE_RD(sext32(MMU.amo_uint32(RS1, [&](uint32_t lhs) { return std::min(lhs, uint32_t(RS2)); })));
ALL_INSN_ADD1;







ALL_INSN_count;
ALL_INSN_cycle(1);
