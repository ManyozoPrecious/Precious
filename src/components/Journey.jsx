import timeline from "../data/timeline";
import TimelineCard from "./TimelineCard";

function Journey() {
  return (
    <section className="max-w-5xl mx-auto px-6 py-24">

      <h2 className="text-5xl font-black text-center mb-4">
        My Journey
      </h2>

      <p className="text-center text-gray-400 mb-16">
        Every project and every technology has been another step forward.
      </p>

      <div>

        {timeline.map((item) => (
          <TimelineCard
            key={item.year}
            item={item}
          />
        ))}

      </div>

    </section>
  );
}

export default Journey;