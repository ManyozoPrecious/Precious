function TimelineCard({ item }) {
  return (
    <div className="relative pl-10 pb-12">

      {/* Vertical Line */}
      <div className="absolute left-3 top-2 h-full w-0.5 bg-white/10"></div>

      {/* Circle */}
      <div className="absolute left-0 top-1 w-6 h-6 rounded-full bg-cyan-500 border-4 border-[#0d1117] shadow-lg shadow-cyan-500/40"></div>

      {/* Content */}
      <div className="rounded-3xl bg-white/5 backdrop-blur-md border border-white/10 p-6 transition-all duration-300 hover:scale-[1.02] hover:border-cyan-400/40">

        <p className="text-cyan-400 font-semibold">
          {item.year}
        </p>

        <h3 className="text-2xl font-bold mt-2">
          {item.title}
        </h3>

        <p className="text-gray-400 mt-4 leading-7">
          {item.description}
        </p>

      </div>

    </div>
  );
}

export default TimelineCard;