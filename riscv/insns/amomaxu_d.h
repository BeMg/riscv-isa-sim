require_extension('A');
require_rv64;
WRITE_RD(MMU.amo_uint64(RS1, [&](uint64_t lhs) { return std::max(lhs, RS2); }));
ALL_INSN_ADD1;


ALL_INSN_count;
ALL_INSN_cycle(1);
